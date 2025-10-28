> What interface does your programming language provide for signal handling? Are you allowed to call arbitrary functions from the signal handler? 

For Rust, it is [nix::sys::signal](https://docs.rs/nix/latest/nix/sys/signal/index.html), in the [nix crate](https://docs.rs/nix/latest/nix/index.html).

There does not *seem* to be any restrictions on what can be invoked from within the signal handler, but will confirm in the final phase of the k-v server (i.e., compaction function).

