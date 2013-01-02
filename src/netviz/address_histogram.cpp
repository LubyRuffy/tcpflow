/**
 * address_histogram.cpp: 
 * Show packets received vs address
 *
 * This source file is public domain, as it is not based on the original tcpflow.
 *
 * Author: Michael Shick <mike@shick.in>
 *
 */

#include "config.h"
#include "tcpflow.h"

#include "address_histogram.h"

const address_histogram::config_t address_histogram::default_config = {
    /* graph */ plot::default_config,
    /* relationship */ address_histogram::SND_OR_RCV,
    /* bar_space_factor */ 1.2,
    /* max_bars */ 10
};

void address_histogram::ingest_packet(const packet_info &pi)
{
}

void address_histogram::render(cairo_t *cr, const plot::bounds_t &bounds)
{
#ifdef CAIRO_PDF_AVAILABLE
    plot::ticks_t ticks;
    plot::legend_t legend;
    plot::bounds_t content_bounds(0.0, 0.0, bounds.width,
            bounds.height);
    //// have the plot class do labeling, axes, legend etc
    plot::render(cr, bounds, ticks, legend, conf.graph, content_bounds);

    //// fill borders rendered by plot class
    //render_bars(cr, content_bounds, vars);
#endif
}