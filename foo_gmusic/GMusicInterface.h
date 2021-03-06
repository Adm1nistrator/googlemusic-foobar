#pragma once
#include <memory>
#include <string>
#include <vector>
#include "disableWarnings.h"
MSC_DISABLE_WARNINGS
MSC_DISABLE_SPECIFIC_WARNING(4702)
#include "foobar2000.h"
MSC_RESTORE_WARNINGS
#include <boost/optional.hpp>
MSC_RESTORE_WARNINGS
#include "SongInfo.h"

namespace GMusicApi
{
class Module;
class Mobileclient;
struct Song;
}

namespace foo_gmusic
{

class GMusicInterface
{
public:
    static GMusicInterface& instance();
    void login();
    std::vector<SongInfo> songs(bool include_deleted = false);
    pfc::string8 deviceId();
    pfc::string8 streamUrl(const pfc::string8& songId, boost::optional<pfc::string8> deviceId = boost::none);

private:
    GMusicInterface();
    ~GMusicInterface();

    std::unique_ptr<GMusicApi::Module>          m_module;
    std::unique_ptr<GMusicApi::Mobileclient>    m_client;
    bool                                        m_isLoggedIn = false;
    pfc::string8                                m_deviceId;
};

} // namespace foo_gmusic