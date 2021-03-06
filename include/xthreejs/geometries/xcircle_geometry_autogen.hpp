#ifndef XTHREE_CIRCLE_GEOMETRY_HPP
#define XTHREE_CIRCLE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // circle_geometry declaration
    //

    template<class D>
    class xcircle_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, segments, 8);
        XPROPERTY(double, derived_type, thetaStart, 0);
        XPROPERTY(double, derived_type, thetaLength, 6.283185307179586);
        XPROPERTY(std::string, derived_type, type, "CircleGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xcircle_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using circle_geometry = xw::xmaterialize<xcircle_geometry>;

    using circle_geometry_generator = xw::xgenerator<xcircle_geometry>;

    //
    // circle_geometry implementation
    //


    template <class D>
    inline void xcircle_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(segments, state, buffers);
        xw::set_patch_from_property(thetaStart, state, buffers);
        xw::set_patch_from_property(thetaLength, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xcircle_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(segments, patch, buffers);
        xw::set_property_from_patch(thetaStart, patch, buffers);
        xw::set_property_from_patch(thetaLength, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xcircle_geometry<D>::xcircle_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcircle_geometry<D>::set_defaults()
    {
        this->_model_name() = "CircleGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcircle_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xcircle_geometry>;
        extern template xw::xmaterialize<xthree::xcircle_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xcircle_geometry>>;
        extern template class xw::xgenerator<xthree::xcircle_geometry>;
        extern template xw::xgenerator<xthree::xcircle_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xcircle_geometry>>;
    #endif
#endif

#endif