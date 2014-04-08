#include <bitlbee.h>

static void gvoice_init(account_t *acc) {
  set_t *s;

  s = set_add(&acc->set, "authcode", NULL, gvoice_eval_authcode, acc);
  s->flags = SET_NULL_OK | SET_HIDDEN | SET_NOSAVE;

  s = set_add(&acc->set, "token", NULL, NULL, acc);
  s->flags = SET_NULL_OK | SET_HIDDEN | SET_PASSWORD;

  set_add(&acc->set, "password", NULL, gvoice_eval_password, acc);
}

static void gvoice_login(account_t *acc) {
}

static void gvoice_logout(struct im_connection *ic) {
}

static int gvoice_buddy_msg(struct im_connection *ic, char *to, char *message, int flags) {
  return 0;
}

static void gvoice_add_buddy(struct im_connection *ic, char *name, char *group) {
  // TODO add google contact
}

static void gvoice_remove_buddy(struct im_connection *ic, char *name, char *group) {
  // TODO remove google contact
}

static void gvoice_get_info(struct im_connection *ic, char *name) {
  // TODO get google contact info
}

void init_plugin(void) {
  struct prpl *ret = g_new0(struct prpl, 1);

  ret->name = "gvoice";
  ret->options = OPT_NOOTR;

  ret->init = gvoice_init;
  ret->login = gvoice_login;
  ret->logout = gvoice_logout;

  ret->buddy_msg = gvoice_buddy_msg;
  ret->add_buddy = gvoice_add_buddy;
  ret->remove_buddy = gvoice_remove_buddy;
  ret->get_info = gvoice_get_info;
  ret->handle_cmp = g_strcasecmp;

  register_protocol(ret);
}
