#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <string>

namespace wot {
    class Resource {
        public:
/************CHANGE RESOURCETYPE******************
	    type resourceType;
*/
	    std::string resourceType;
	    std::string imagePath;
	    std::string configPath;
	    
	    Resource(void);
	    Resource(std::string valResourceType, std::string valImagePath, std::string valConfigPath);
    };

} /* wot */

#endif /* __RESOURCE_H__ */
