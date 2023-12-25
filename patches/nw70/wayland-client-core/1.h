
struct wl_event_queue;

void
wl_event_queue_destroy(struct wl_event_queue *queue);

void
wl_proxy_marshal(struct wl_proxy *p, uint32_t opcode, ...);
//----replace

struct wl_event_queue;

/** Destroy proxy after marshalling
 * @ingroup wl_proxy
 */
#define WL_MARSHAL_FLAG_DESTROY (1 << 0)

void
wl_event_queue_destroy(struct wl_event_queue *queue);

struct wl_proxy *
wl_proxy_marshal_flags(struct wl_proxy *proxy, uint32_t opcode,
		       const struct wl_interface *interface,
		       uint32_t version,
		       uint32_t flags, ...);

void
wl_proxy_marshal(struct wl_proxy *p, uint32_t opcode, ...);
