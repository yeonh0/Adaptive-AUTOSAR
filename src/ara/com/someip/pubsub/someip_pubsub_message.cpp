#include <utility>
#include "./someip_pubsub_message.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                SomeIpPubsubMessage::SomeIpPubsubMessage() : SomeIpMessage(0,
                                                                     0,
                                                                     1,
                                                                     1,
                                                                     SomeIpMessageType::Request)
                {
                }

                SomeIpPubsubMessage::SomeIpPubsubMessage(uint32_t messageId,
                                                   uint16_t clientId,
                                                   uint16_t sessionId,
                                                   uint8_t protocolVersion,
                                                   uint8_t interfaceVersion,
                                                   const std::vector<uint8_t> &PubsubPayload) : SomeIpMessage(messageId,
                                                                                                           clientId,
                                                                                                           protocolVersion,
                                                                                                           interfaceVersion,
                                                                                                           SomeIpMessageType::Request,
                                                                                                           sessionId),
                                                                                             mPubsubPayload{PubsubPayload}
                {
                }

                SomeIpPubsubMessage::SomeIpPubsubMessage(uint32_t messageId,
                                                   uint16_t clientId,
                                                   uint16_t sessionId,
                                                   uint8_t protocolVersion,
                                                   uint8_t interfaceVersion,
                                                   std::vector<uint8_t> &&PubsubPayload) : SomeIpMessage(messageId,
                                                                                                      clientId,
                                                                                                      protocolVersion,
                                                                                                      interfaceVersion,
                                                                                                      SomeIpMessageType::Request,
                                                                                                      sessionId),
                                                                                        mPubsubPayload{std::move(PubsubPayload)}
                {
                }

                SomeIpPubsubMessage::SomeIpPubsubMessage(uint32_t messageId,
                                                   uint16_t clientId,
                                                   uint16_t sessionId,
                                                   uint8_t protocolVersion,
                                                   uint8_t interfaceVersion,
                                                   SomeIpReturnCode returnCode,
                                                   const std::vector<uint8_t> &PubsubPayload) : SomeIpMessage(messageId,
                                                                                                           clientId,
                                                                                                           protocolVersion,
                                                                                                           interfaceVersion,
                                                                                                           returnCode == SomeIpReturnCode::eOK ? SomeIpMessageType::Response : SomeIpMessageType::Error,
                                                                                                           returnCode,
                                                                                                           sessionId),
                                                                                             mPubsubPayload{PubsubPayload}
                {
                }

                uint32_t SomeIpPubsubMessage::Length() const noexcept
                {
                    const size_t cHeaderLength{8};
                    auto _result{
                        static_cast<uint32_t>(cHeaderLength + mPubsubPayload.size())};

                    return _result;
                }

                std::vector<uint8_t> SomeIpPubsubMessage::Payload() const
                {
                    // General SOME/IP header payload insertion
                    std::vector<uint8_t> _result = SomeIpMessage::Payload();
                    _result.insert(
                        _result.end(), mPubsubPayload.cbegin(), mPubsubPayload.cend());

                    return _result;
                }

                const std::vector<uint8_t> &SomeIpPubsubMessage::PubsubPayload() const
                {
                    return mPubsubPayload;
                }

                SomeIpPubsubMessage SomeIpPubsubMessage::Deserialize(
                    const std::vector<uint8_t> &payload)
                {
                    const size_t cHeaderSize{16};

                    size_t _lengthOffset{4};
                    uint32_t _lengthInt{
                        helper::ExtractInteger(payload, _lengthOffset)};
                    auto _length{static_cast<size_t>(_lengthInt)};

                    SomeIpPubsubMessage _result;
                    SomeIpMessage::Deserialize(&_result, payload);
                    _result.mPubsubPayload =
                        std::vector<uint8_t>(
                            payload.cbegin() + cHeaderSize,
                            payload.cbegin() + cHeaderSize + _length - _lengthOffset);

                    return _result;
                }
            }
        }
    }
}