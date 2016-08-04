#include <IOKit/IOKitLib.h>
#include <IOKit/hidsystem/IOHIDShared.h>
#include <IOKit/hidsystem/ev_keymap.h>

#include <iostream>
#include <memory>
#include <thread>

#include "include_boost.hpp"

#include "connection_manager.hpp"
#include "grabber_client.hpp"
#include "io_hid_post_event_wrapper.hpp"
#include "receiver.hpp"
#include "session.hpp"

int main(int argc, const char* argv[]) {
  io_hid_post_event_wrapper w;
  w.start();
  w.post_key(0xa0, KRBN_EV_TYPE_KEY_DOWN, 0, false);
  w.post_key(0xa0, KRBN_EV_TYPE_KEY_UP, 0, false);

  connection_manager manager;

  receiver r;
  r.start();

  CFRunLoopRun();
  return 0;
}