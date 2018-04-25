#ifndef XTHREE_RAW_SHADER_MATERIAL_HPP
#define XTHREE_RAW_SHADER_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xshader_material_autogen.hpp"

namespace xthree
{
    //
    // raw_shader_material declaration
    //

    template<class D>
    class xraw_shader_material : public xshader_material<D>
    {
    public:

        using base_type = xshader_material<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xraw_shader_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using raw_shader_material = xw::xmaterialize<xraw_shader_material>;

    using raw_shader_material_generator = xw::xgenerator<xraw_shader_material>;

    //
    // raw_shader_material implementation
    //

    template <class D>
    inline void xraw_shader_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xraw_shader_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xraw_shader_material<D>::xraw_shader_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xraw_shader_material<D>::set_defaults()
    {
        this->_model_name() = "RawShaderMaterialModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xraw_shader_material));
//}
#endif