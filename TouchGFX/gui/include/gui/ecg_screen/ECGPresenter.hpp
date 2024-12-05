#ifndef ECGPRESENTER_HPP
#define ECGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ECGView;

class ECGPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ECGPresenter(ECGView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ECGPresenter() {}

private:
    ECGPresenter();

    ECGView& view;
};

#endif // ECGPRESENTER_HPP
