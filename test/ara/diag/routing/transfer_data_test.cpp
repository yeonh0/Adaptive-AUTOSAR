#include <gtest/gtest.h>
#include "../../../../src/ara/diag/routing/transfer_data.h"

namespace ara
{
    namespace diag
    {
        namespace routing
        {
            class TransferDataTest : public testing::Test
            {
            private:
                static core::InstanceSpecifier mSpecifier;

            protected:
                const uint8_t cSid{0x36};

                TransferData Service;
                MetaInfo GeneralMetaInfo;

                bool TryGetNrc(const std::vector<uint8_t> &requestData, uint8_t &nrc)
                {
                    const size_t cRejectedSidIndex{1};
                    const size_t cNrcIndex{2};

                    CancellationHandler _cancellationHandler(false);

                    std::future<OperationOutput> _responseFuture{
                        Service.HandleMessage(
                            requestData,
                            GeneralMetaInfo,
                            std::move(_cancellationHandler))};

                    OperationOutput _response{_responseFuture.get()};

                    uint8_t _sid{_response.responseData.at(cRejectedSidIndex)};
                    if (_sid == cSid)
                    {
                        nrc = _response.responseData.at(cNrcIndex);
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }

            public:
                TransferDataTest() : Service{mSpecifier},
                                     GeneralMetaInfo(Context::kDoIP)
                {
                }
            };

            core::InstanceSpecifier TransferDataTest::mSpecifier{"Instance0"};

            TEST_F(TransferDataTest, ValidTransferConfiguration)
            {
                const TransferDirection cTransferDirection{TransferDirection::kDownload};
                const size_t cMemoryAddress{512};
                const size_t cMemorySize{64};

                EXPECT_TRUE(
                    Service.TrySetTransferConfiguration(
                        cTransferDirection, cMemoryAddress, cMemorySize));
            }

            TEST_F(TransferDataTest, InvalidTransferConfiguration)
            {
                const TransferDirection cValidTransferDirection{TransferDirection::kDownload};
                const size_t cValidMemoryAddress{512};
                const size_t cValidMemorySize{64};

                const TransferDirection cInvalidTransferDirection{TransferDirection::kNone};
                const size_t cInvalidMemoryAddress{2048};
                const size_t cInvalidMemorySize{1024};
                const size_t cZeroMemorySize{0};

                EXPECT_FALSE(
                    Service.TrySetTransferConfiguration(
                        cInvalidTransferDirection, cValidMemoryAddress, cValidMemorySize));

                EXPECT_FALSE(
                    Service.TrySetTransferConfiguration(
                        cValidTransferDirection, cInvalidMemoryAddress, cValidMemorySize));

                EXPECT_FALSE(
                    Service.TrySetTransferConfiguration(
                        cValidTransferDirection, cValidMemoryAddress, cZeroMemorySize));

                EXPECT_FALSE(
                    Service.TrySetTransferConfiguration(
                        cValidTransferDirection, cValidMemoryAddress, cInvalidMemorySize));
            }

            TEST_F(TransferDataTest, TransferConfigurationReset)
            {
                const TransferDirection cTransferDirection{TransferDirection::kDownload};
                const size_t cMemoryAddress{512};
                const size_t cMemorySize{64};

                EXPECT_FALSE(Service.TryResetTransferConfiguration());

                Service.TrySetTransferConfiguration(
                    cTransferDirection, cMemoryAddress, cMemorySize);

                EXPECT_TRUE(Service.TryResetTransferConfiguration());
            }

            TEST_F(TransferDataTest, IncorrectMessageLengthScenario)
            {
                const uint8_t cExpectedNrc{0x13};

                uint8_t _actualNrc;
                std::vector<uint8_t> _requestData{cSid};
                bool _hasNrc{TryGetNrc(_requestData, _actualNrc)};

                EXPECT_TRUE(_hasNrc);
                EXPECT_EQ(cExpectedNrc, _actualNrc);
            }

            TEST_F(TransferDataTest, RequestSequenceErrorScenario)
            {
                const uint8_t cExpectedNrc{0x24};
                const uint8_t cBlockSequenceCounter{1};

                uint8_t _actualNrc;
                std::vector<uint8_t> _requestData{cSid, cBlockSequenceCounter};
                bool _hasNrc{TryGetNrc(_requestData, _actualNrc)};

                EXPECT_TRUE(_hasNrc);
                EXPECT_EQ(cExpectedNrc, _actualNrc);
            }
        }
    }
}