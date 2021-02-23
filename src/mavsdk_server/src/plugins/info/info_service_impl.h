// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/info/info.proto)

#include "info/info.grpc.pb.h"
#include "plugins/info/info.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename Info = Info>
class InfoServiceImpl final : public rpc::info::InfoService::Service {
public:
    InfoServiceImpl(Info& info) : _info(info) {}


    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Info::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_info_result = new rpc::info::InfoResult();
        rpc_info_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_info_result->set_result_str(ss.str());

        response->set_allocated_info_result(rpc_info_result);
    }




    static std::unique_ptr<rpc::info::FlightInfo> translateToRpcFlightInfo(const mavsdk::Info::FlightInfo &flight_info)
    {
        auto rpc_obj = std::make_unique<rpc::info::FlightInfo>();


            
        rpc_obj->set_time_boot_ms(flight_info.time_boot_ms);
            
        
            
        rpc_obj->set_flight_uid(flight_info.flight_uid);
            
        

        return rpc_obj;
    }

    static mavsdk::Info::FlightInfo translateFromRpcFlightInfo(const rpc::info::FlightInfo& flight_info)
    {
        mavsdk::Info::FlightInfo obj;


            
        obj.time_boot_ms = flight_info.time_boot_ms();
            
        
            
        obj.flight_uid = flight_info.flight_uid();
            
        
        return obj;
    }





    static std::unique_ptr<rpc::info::Identification> translateToRpcIdentification(const mavsdk::Info::Identification &identification)
    {
        auto rpc_obj = std::make_unique<rpc::info::Identification>();


            
        rpc_obj->set_hardware_uid(identification.hardware_uid);
            
        

        return rpc_obj;
    }

    static mavsdk::Info::Identification translateFromRpcIdentification(const rpc::info::Identification& identification)
    {
        mavsdk::Info::Identification obj;


            
        obj.hardware_uid = identification.hardware_uid();
            
        
        return obj;
    }





    static std::unique_ptr<rpc::info::Product> translateToRpcProduct(const mavsdk::Info::Product &product)
    {
        auto rpc_obj = std::make_unique<rpc::info::Product>();


            
        rpc_obj->set_vendor_id(product.vendor_id);
            
        
            
        rpc_obj->set_vendor_name(product.vendor_name);
            
        
            
        rpc_obj->set_product_id(product.product_id);
            
        
            
        rpc_obj->set_product_name(product.product_name);
            
        

        return rpc_obj;
    }

    static mavsdk::Info::Product translateFromRpcProduct(const rpc::info::Product& product)
    {
        mavsdk::Info::Product obj;


            
        obj.vendor_id = product.vendor_id();
            
        
            
        obj.vendor_name = product.vendor_name();
            
        
            
        obj.product_id = product.product_id();
            
        
            
        obj.product_name = product.product_name();
            
        
        return obj;
    }





    static std::unique_ptr<rpc::info::Version> translateToRpcVersion(const mavsdk::Info::Version &version)
    {
        auto rpc_obj = std::make_unique<rpc::info::Version>();


            
        rpc_obj->set_flight_sw_major(version.flight_sw_major);
            
        
            
        rpc_obj->set_flight_sw_minor(version.flight_sw_minor);
            
        
            
        rpc_obj->set_flight_sw_patch(version.flight_sw_patch);
            
        
            
        rpc_obj->set_flight_sw_vendor_major(version.flight_sw_vendor_major);
            
        
            
        rpc_obj->set_flight_sw_vendor_minor(version.flight_sw_vendor_minor);
            
        
            
        rpc_obj->set_flight_sw_vendor_patch(version.flight_sw_vendor_patch);
            
        
            
        rpc_obj->set_os_sw_major(version.os_sw_major);
            
        
            
        rpc_obj->set_os_sw_minor(version.os_sw_minor);
            
        
            
        rpc_obj->set_os_sw_patch(version.os_sw_patch);
            
        
            
        rpc_obj->set_flight_sw_git_hash(version.flight_sw_git_hash);
            
        
            
        rpc_obj->set_os_sw_git_hash(version.os_sw_git_hash);
            
        

        return rpc_obj;
    }

    static mavsdk::Info::Version translateFromRpcVersion(const rpc::info::Version& version)
    {
        mavsdk::Info::Version obj;


            
        obj.flight_sw_major = version.flight_sw_major();
            
        
            
        obj.flight_sw_minor = version.flight_sw_minor();
            
        
            
        obj.flight_sw_patch = version.flight_sw_patch();
            
        
            
        obj.flight_sw_vendor_major = version.flight_sw_vendor_major();
            
        
            
        obj.flight_sw_vendor_minor = version.flight_sw_vendor_minor();
            
        
            
        obj.flight_sw_vendor_patch = version.flight_sw_vendor_patch();
            
        
            
        obj.os_sw_major = version.os_sw_major();
            
        
            
        obj.os_sw_minor = version.os_sw_minor();
            
        
            
        obj.os_sw_patch = version.os_sw_patch();
            
        
            
        obj.flight_sw_git_hash = version.flight_sw_git_hash();
            
        
            
        obj.os_sw_git_hash = version.os_sw_git_hash();
            
        
        return obj;
    }




    static rpc::info::InfoResult::Result translateToRpcResult(const mavsdk::Info::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Info::Result::Unknown:
                return rpc::info::InfoResult_Result_RESULT_UNKNOWN;
            case mavsdk::Info::Result::Success:
                return rpc::info::InfoResult_Result_RESULT_SUCCESS;
            case mavsdk::Info::Result::InformationNotReceivedYet:
                return rpc::info::InfoResult_Result_RESULT_INFORMATION_NOT_RECEIVED_YET;
        }
    }

    static mavsdk::Info::Result translateFromRpcResult(const rpc::info::InfoResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::info::InfoResult_Result_RESULT_UNKNOWN:
                return mavsdk::Info::Result::Unknown;
            case rpc::info::InfoResult_Result_RESULT_SUCCESS:
                return mavsdk::Info::Result::Success;
            case rpc::info::InfoResult_Result_RESULT_INFORMATION_NOT_RECEIVED_YET:
                return mavsdk::Info::Result::InformationNotReceivedYet;
        }
    }




    grpc::Status GetFlightInformation(
        grpc::ServerContext* /* context */,
        const rpc::info::GetFlightInformationRequest* /* request */,
        rpc::info::GetFlightInformationResponse* response) override
    {
        

        auto result = _info.get_flight_information();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_allocated_flight_info(translateToRpcFlightInfo(result.second).release());
            
        }


        return grpc::Status::OK;
    }

    grpc::Status GetIdentification(
        grpc::ServerContext* /* context */,
        const rpc::info::GetIdentificationRequest* /* request */,
        rpc::info::GetIdentificationResponse* response) override
    {
        

        auto result = _info.get_identification();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_allocated_identification(translateToRpcIdentification(result.second).release());
            
        }


        return grpc::Status::OK;
    }

    grpc::Status GetProduct(
        grpc::ServerContext* /* context */,
        const rpc::info::GetProductRequest* /* request */,
        rpc::info::GetProductResponse* response) override
    {
        

        auto result = _info.get_product();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_allocated_product(translateToRpcProduct(result.second).release());
            
        }


        return grpc::Status::OK;
    }

    grpc::Status GetVersion(
        grpc::ServerContext* /* context */,
        const rpc::info::GetVersionRequest* /* request */,
        rpc::info::GetVersionResponse* response) override
    {
        

        auto result = _info.get_version();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_allocated_version(translateToRpcVersion(result.second).release());
            
        }


        return grpc::Status::OK;
    }

    grpc::Status GetSpeedFactor(
        grpc::ServerContext* /* context */,
        const rpc::info::GetSpeedFactorRequest* /* request */,
        rpc::info::GetSpeedFactorResponse* response) override
    {
        

        auto result = _info.get_speed_factor();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_speed_factor(result.second);
            
        }


        return grpc::Status::OK;
    }


    void stop() {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom) {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom) {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end(); /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    Info &_info;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises {};
};

} // namespace mavsdk_server
} // namespace mavsdk