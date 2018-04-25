#ifndef XTHREE_BUFFER_GEOMETRY_HPP
#define XTHREE_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbase_buffer_geometry_autogen.hpp"

namespace xthree
{
    //
    // buffer_geometry declaration
    //

    template<class D>
    class xbuffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(dict, derived_type, attributes, {});
        
        XPROPERTY(int, derived_type, MaxIndex, 65535);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, _ref_geometry);

    protected:

        xbuffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using buffer_geometry = xw::xmaterialize<xbuffer_geometry>;

    using buffer_geometry_generator = xw::xgenerator<xbuffer_geometry>;

    //
    // buffer_geometry implementation
    //

    template <class D>
    inline void xbuffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(attributes, state, buffers);
        xw::set_patch_from_property(MaxIndex, state, buffers);
        xw::set_patch_from_property(_ref_geometry, state, buffers);
    }

    template <class D>
    inline void xbuffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(attributes, patch, buffers);
        xw::set_property_from_patch(MaxIndex, patch, buffers);
        xw::set_property_from_patch(_ref_geometry, patch, buffers);
    }

    template <class D>
    inline xbuffer_geometry<D>::xbuffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbuffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "BufferGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbuffer_geometry));
//}
#endif