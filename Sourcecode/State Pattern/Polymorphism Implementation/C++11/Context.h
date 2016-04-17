#ifndef SRC_CONTEXT_H_
#define SRC_CONTEXT_H_

#include "State.h"

#include <unordered_map>
#include <memory>

using namespace std;
class Context {
public:
    enum SIGNAL{ON=0, OFF=1, DESTROY=2};

    Context();

    void initialize(weak_ptr<Context> context);

    void input(int signal);

    void on();
    void off();
    void destroy();

    void status();

    unique_ptr<State> state;

    int numOfChanges;
private:
    unordered_map<int, function<void()>> functionMap;
};

#endif /* SRC_CONTEXT_H_ */
