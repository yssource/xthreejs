#ifndef XTHREE_WEBGL_LIGHTS_HPP
#define XTHREE_WEBGL_LIGHTS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_lights declaration
    //

    template<class D>
    class xwebgl_lights : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xwebgl_lights();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_lights = xw::xmaterialize<xwebgl_lights>;

    using webgl_lights_generator = xw::xgenerator<xwebgl_lights>;

    //
    // webgl_lights implementation
    //

    template <class D>
    inline void xwebgl_lights<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_lights<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_lights<D>::xwebgl_lights()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_lights<D>::set_defaults()
    {
        this->_model_name() = "WebGLLightsModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_lights));
//}
#endif