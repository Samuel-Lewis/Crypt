#pragma once

// delegate to allow requesting region update

/*
 * usage:
 * give class that wants to make update requests a UpdateRequestDelegate *delegate;
 * when you want to make a request. call requestUpdate(delegate)
 * set the object that is in the GameController. e.g a player 's delegate to this
 * e.g Player.delegate = this;
 */

class UpdateRequestDelegate
{
public:
    virtual ~UpdateRequestDelegate(){}
    virtual void updateRequested(UpdateRequestDelegate *sender) = 0;
};

static inline void requestUpdate(UpdateRequestDelegate *delegate)
{
    if (delegate)
    {
        delegate->updateRequested(delegate);
    }
}