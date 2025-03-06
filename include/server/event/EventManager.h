
#include "IListener.h"
#include <vector>

using namespace std;

class EventManager {
protected:
    vector<IListener> listeners;
public:
    EventManager() {
        listeners = vector<IListener>;
    }

    void registerListener(IListener listener){
        listeners.push_back(listener);
    }
    void unregisterListener(IListener){}

    

    
};