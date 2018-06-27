#include "libopenair/configuration.hh"
#include <fstream>
#include <sstream>
#include <istream>

namespace __CONFIGURATION__INTERNAL__NS__ {
    std::string trim(std::string const& source,
                     char const* delims = " \t\r\n") {
        std::string result(source);
        std::string::size_type index = result.find_last_not_of(delims);
        if(index != std::string::npos) {
            result.erase(++index);
        }
        index = result.find_first_not_of(delims);
        if(index != std::string::npos) {
            result.erase(0, index);
        } else {
            result.erase();
        }
        return result;
    }
}

std::string openair::get_configuration_file_path() {
    std::string path = getenv(HOME_ENV.c_str());
    path = path + "/";
    path = path + CONFIGURATION_FILE_NAME;
    return path;
}

openair::ConfigurationData::ConfigurationData() { }

openair::ConfigurationData::~ConfigurationData() { }


std::ostream& operator<<(std::ostream& os,
                         const openair::ConfigurationData& config){
    os << openair::DATABASE_PATH_KEY << "="
       << config.database_path << "\n"
       << openair::SERVICE_ADDRESS_KEY << "="
       << config.service_address << "\n"
       << openair::VPN_REGISTRATION_METHOD_KEY << "="
       << config.vpn_registration_method << "\n"
       << openair::SEND_DATA_METHOD_KEY << "="
       << config.send_data_method << "\n"
       << openair::SEND_ERRORS_METHOD_KEY << "="
       << config.send_errors_method << "\n";
    return os;
}
std::istream& operator>>(std::istream& is,
                         openair::ConfigurationData& config) {
    std::string line;
    int posEqual;
    while (std::getline(is, line)) {
        if (!line.length() ||
            line[0] == '#' ||
            line[0] == ';') {
            continue;
        }
        posEqual = line.find('=');
        std::string key = __CONFIGURATION__INTERNAL__NS__::trim(
            line.substr(0, posEqual));
        
        std::string value = line.substr(posEqual + 1);
        if (key == openair::DATABASE_PATH_KEY) {
            config.database_path =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        } else if (key == openair::SERVICE_ADDRESS_KEY) {
            config.service_address =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        } else if (
            key == openair::VPN_REGISTRATION_METHOD_KEY) {
            config.vpn_registration_method =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        } else if (key == openair::SEND_DATA_METHOD_KEY) {
            config.send_data_method =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        } else if (key == openair::SEND_ERRORS_METHOD_KEY) {
            config.send_errors_method =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        } else if (
            key == openair::VPN_REGISTRATION_METHOD_KEY) {
            config.send_errors_method =
                __CONFIGURATION__INTERNAL__NS__::trim(value);
        }
    }    
    return is;
}

bool operator==(const openair::ConfigurationData& a,
                const openair::ConfigurationData& b) {
    return a.database_path == b.database_path &&
        a.service_address == b.service_address &&
        a.vpn_registration_method == b.vpn_registration_method &&
        a.send_data_method == b.send_data_method &&
        a.send_errors_method == b.send_errors_method;
}

bool operator!=(const openair::ConfigurationData& a,
                const openair::ConfigurationData& b) {
    return !(a == b);
}
