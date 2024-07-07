#include "rpc_server_test.h"

using namespace ara::com::rpc;

int main() {
    AsyncBsdSocketLib::Poller poller;
    std::string serverIpAddress = "0.0.0.0";
    uint16_t serverPort = 33333;
    uint8_t protocolVersion = 1;
    uint8_t interfaceVersion = 1;

    RpcServerTest server(&poller, serverIpAddress, serverPort, protocolVersion, interfaceVersion);

    while (1) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

// const uint8_t RpcServerTest::cProtocolVersion;
//                 const uint8_t RpcServerTest::cInterfaceVersion;

//                 TEST_F(RpcServerTest, OkHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eOK};

//                     uint32_t _messageId{GetMessageId(cServiceId, cTrueMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, NotOkHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eNotOk};

//                     uint32_t _messageId{GetMessageId(cServiceId, cFalseMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, UnknownMethodHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eUnknownMethod};
//                     const uint16_t cUnknownMethod{3};

//                     uint32_t _messageId{GetMessageId(cServiceId, cUnknownMethod)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, UnknownServiceHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eUnknownService};
//                     const uint16_t cUnknownService{2};

//                     uint32_t _messageId{GetMessageId(cUnknownService, cTrueMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, WrongMessageTypeHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eWrongMessageType};

//                     uint32_t _messageId{GetMessageId(cServiceId, cTrueMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInterfaceVersion,
//                         cExpectedResult,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, WrongProtocolVersionHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eWrongProtocolVersion};
//                     const uint16_t cInvalidProtocolVersion{2};

//                     uint32_t _messageId{GetMessageId(cServiceId, cTrueMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cInvalidProtocolVersion,
//                         cInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, WrongInterfaceVersionHandle)
//                 {
//                     const SomeIpReturnCode cExpectedResult{SomeIpReturnCode::eWrongInterfaceVersion};
//                     const uint16_t cInvalidInterfaceVersion{2};

//                     uint32_t _messageId{GetMessageId(cServiceId, cTrueMethodId)};
//                     SomeIpRpcMessage _request(
//                         _messageId,
//                         cClientId,
//                         cSessionId,
//                         cProtocolVersion,
//                         cInvalidInterfaceVersion,
//                         cRpcPayload);

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(_request.Payload(), _responsePayload)};
//                     EXPECT_TRUE(_handled);

//                     SomeIpRpcMessage _response{
//                         SomeIpRpcMessage::Deserialize(_responsePayload)};
//                     SomeIpReturnCode _actualResult{_response.ReturnCode()};
//                     EXPECT_EQ(cExpectedResult, _actualResult);
//                 }

//                 TEST_F(RpcServerTest, NoHandle)
//                 {
//                     const std::vector<uint8_t> cRequestPayload;

//                     std::vector<uint8_t> _responsePayload;
//                     bool _handled{
//                         TryInvokeHandler(cRequestPayload, _responsePayload)};
//                     EXPECT_FALSE(_handled);
//                 }
//             }
//         }
//     }
// }

// TEST_F(RpcClientTest, SendMethod)
//                 {
//                     const uint16_t cClientId{2};
//                     const std::vector<uint8_t> cRpcPayload;
//                     const uint16_t cExpectedResult{1};

//                     Send(cServiceId, cMethodId, cClientId, cRpcPayload);
//                     EXPECT_EQ(cExpectedResult, LastSessionId);

//                     Send(cServiceId, cMethodId, cClientId, cRpcPayload);
//                     EXPECT_NE(cExpectedResult, LastSessionId);
//                 }