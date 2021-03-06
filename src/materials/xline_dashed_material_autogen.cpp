#include "xthreejs/materials/xline_dashed_material_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xline_dashed_material>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xline_dashed_material>;
    template xw::xmaterialize<xthree::xline_dashed_material>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xline_dashed_material>>;
    template class xw::xgenerator<xthree::xline_dashed_material>;
    template xw::xgenerator<xthree::xline_dashed_material>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xline_dashed_material>>;
#endif
