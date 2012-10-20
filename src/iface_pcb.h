/*
 * This file is part of tcpflow by Simson Garfinkel <simsong@acm.org>.
 * Originally by Jeremy Elson <jelson@circlemud.org>.
 *
 * This source code is under the GNU Public License (GPL).  See
 * LICENSE for details.
 *
 * Author: Michael Shick <mike@shick.in>
 *
 */

#include "tcpflow.h"
#include <vector>

// Packet callback (PCB): dumb plug-in interface that simply forwards all
// packets to plugins

// Namespace rather than a class because C style callbacks don't work on
// member functions due to their not following C invocation convention
namespace pcb
{
    // types
    typedef enum {
        none = -1,
        startup = 0,
        scan = 1,
        shutdown = 2
    } phase_t;
    typedef void callback_t(phase_t phase, const struct pcap_pkthdr *h,
            const u_char *p);

    // functions
    void init(pcap_handler const wrapped_, const bool passthrough_);
    void load_plugin(const callback_t *new_plugin);
    void do_startup();
    void handle(u_char *user_args, const struct pcap_pkthdr *h,
            const u_char *p);
    void do_shutdown();
}
