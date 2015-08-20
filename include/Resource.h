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
	    
	    Resource();
	    Resource(const Resource&);
	    Resource(std::string, std::string, std::string);

        void operator=(Resource);
    };

} /* wot */

#endif /* __RESOURCE_H__ */
