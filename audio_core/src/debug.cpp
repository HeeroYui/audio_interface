/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license GPL v3 (see license file)
 */

#include "debug.h"

int32_t appl::getLogId() {
	static int32_t g_val = etk::log::registerInstance("test");
	return g_val;
}

