#ifndef XTHREE_IMAGE_LOADER_HPP
#define XTHREE_IMAGE_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // image_loader declaration
    //

    template<class D>
    class ximage_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        ximage_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using image_loader = xw::xmaterialize<ximage_loader>;

    using image_loader_generator = xw::xgenerator<ximage_loader>;

    //
    // image_loader implementation
    //


    template <class D>
    inline void ximage_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void ximage_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline ximage_loader<D>::ximage_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void ximage_loader<D>::set_defaults()
    {
        this->_model_name() = "ImageLoaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::ximage_loader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::ximage_loader>;
        extern template xw::xmaterialize<xthree::ximage_loader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::ximage_loader>>;
        extern template class xw::xgenerator<xthree::ximage_loader>;
        extern template xw::xgenerator<xthree::ximage_loader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::ximage_loader>>;
    #endif
#endif

#endif