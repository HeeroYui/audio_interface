/**
 * @author Edouard DUPIN
 * 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_CORE_INTERFACE_INPUT_H__
#define __AUDIO_CORE_INTERFACE_INPUT_H__

#include <river/Manager.h>

namespace appl {
	class InterfaceInput {
		public:
			std11::shared_ptr<river::Manager> m_manager;
			std11::shared_ptr<river::Interface> m_interface;
			ros::Publisher m_stream;
			std11::mutex mutex;
		public:
			InterfaceInput(std11::shared_ptr<river::Manager> _manager,
			               const std::string& _input="microphone",
			               const std::string& _publisher="microphone",
			               bool _feedback=false);
			~InterfaceInput();
		protected:
			void onConnect(const ros::SingleSubscriberPublisher& _pub);
			void onDisConnect(const ros::SingleSubscriberPublisher& _pub);
			void onDataReceived(const void* _data,
			                    const std11::chrono::system_clock::time_point& _time,
			                    size_t _nbChunk,
			                    enum audio::format _format,
			                    uint32_t _frequency,
			                    const std::vector<audio::channel>& _map);
	};
}

#endif