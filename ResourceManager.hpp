#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

/*Create resource descriptions, which are all loaded.
 *Resource Manager will then load actual resource
 *when it is needed and unload when no longer required.
 */
class ResourceManager
{
public:
    ResourceManager()
    {
    }
    ~ResourceManager()
    {
    }

    bool createResource(const std::string name);//argument 2 template
    bool clearResource(unsigned int id);

    getAllResourceAddr();
    getResourceAddrFromID(unsigned int id);//return type template

    getResourceIDFromName(const std::string name);
    getResourceNameIDMap();

protected:

private:
};

#endif
