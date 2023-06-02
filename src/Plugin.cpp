#include <llapi/LoggerAPI.h>
#include <llapi/EventAPI.h>
#include <llapi/mc/Player.hpp>
#include <myplugin/Resource.h>
#include <myplugin/Plugin.h>

namespace my_plugin {

Logger logger(PLUGIN_NAME);

void Entry() {
    logger.info("Hello, world!");
    Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& event) {
        logger.info("Player " + event.mPlayer->getName() + " joined the server!");
        return true;
    });
}

} // namespace my_plugin