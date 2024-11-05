#ifndef SOMEIP_PUBSUB_MESSAGE_H
#define SOMEIP_PUBSUB_MESSAGE_H

#include "../someip_message.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                /// @brief SOME/IP remote procedure call message
                class SomeIpPubsubMessage : public SomeIpMessage
                {
                private:
                    std::vector<uint8_t> mPubsubPayload;

                    SomeIpPubsubMessage();

                public:
                    /// @brief Constructor for Pubsub request message by copying the Pubsub payload
                    /// @param messageId Message ID consisting service and method/event ID
                    /// @param clientId Client ID including ID prefix
                    /// @param sessionId Active session ID
                    /// @param protocolVersion SOME/IP protocol header version
                    /// @param interfaceVersion Service interface version
                    /// @param PubsubPayload Serialized Pubsub request object byte vector
                    SomeIpPubsubMessage(uint32_t messageId,
                                     uint16_t clientId,
                                     uint16_t sessionId,
                                     uint8_t protocolVersion,
                                     uint8_t interfaceVersion,
                                     const std::vector<uint8_t> &PubsubPayload);

                    /// @brief Constructor for Pubsub request message by moving the Pubsub payload
                    /// @param messageId Message ID consisting service and method/event ID
                    /// @param clientId Client ID including ID prefix
                    /// @param sessionId Active session ID
                    /// @param protocolVersion SOME/IP protocol header version
                    /// @param interfaceVersion Service interface version
                    /// @param PubsubPayload Serialized Pubsub request object byte vector
                    SomeIpPubsubMessage(uint32_t messageId,
                                     uint16_t clientId,
                                     uint16_t sessionId,
                                     uint8_t protocolVersion,
                                     uint8_t interfaceVersion,
                                     std::vector<uint8_t> &&PubsubPayload);

                    /// @brief Constructor for Pubsub response or error message
                    /// @param messageId Message ID consisting service and method/event ID
                    /// @param clientId Client ID including ID prefix
                    /// @param sessionId Active session ID
                    /// @param protocolVersion SOME/IP protocol header version
                    /// @param interfaceVersion Service interface version
                    /// @param returnCode Message response/error return code
                    /// @param PubsubPayload Serialized Pubsub response/error object byte vector
                    SomeIpPubsubMessage(uint32_t messageId,
                                     uint16_t clientId,
                                     uint16_t sessionId,
                                     uint8_t protocolVersion,
                                     uint8_t interfaceVersion,
                                     SomeIpReturnCode returnCode,
                                     const std::vector<uint8_t> &PubsubPayload);

                    virtual uint32_t Length() const noexcept override;

                    virtual std::vector<uint8_t> Payload() const override;

                    /// @brief Get the serialized Pubsub object
                    /// @returns Byte vector constant reference
                    const std::vector<uint8_t> &PubsubPayload() const;

                    /// @brief Deserialize a SOME/IP Pubsub message payload
                    /// @param payload Serialized SOME/IP message payload byte array
                    /// @returns SOME/IP Pubsub message filled by deserializing the payload
                    /// @throws std::out_of_range Throws when the payload is corrupted
                    static SomeIpPubsubMessage Deserialize(const std::vector<uint8_t> &payload);
                };
            }
        }
    }
}

#endif