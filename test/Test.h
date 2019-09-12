#include "UpdateService.h"
#include <functional>

using namespace com::anyconnect::update;

class Test
{
    void *handle;
    UpdateService *instance;
    UpdateService *(*create)();
    void (*destroy)(UpdateService *);

public:
    Test();
    ~Test();
    void loadLib(std::string name);
    bool isLoaded();
    void setUpdateCallback();
};
