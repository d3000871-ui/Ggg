# Development roadmap

## Prototype milestones
- [x] Repository and Unreal C++ starter structure
- [x] Third-person character movement and camera
- [ ] Create a playable test map in Unreal Editor
- [ ] Add animation Blueprint and character mesh
- [x] Add starter server-authoritative melee trace and enemy health
- [x] Add replicated starter inventory item stacks\n- [ ] Add equipment, loot and persistent inventory storage
- [ ] Add enemy AI and NPC interactions
- [ ] Add dedicated-server deployment and account service
- [ ] Add Android touch controls and device profiling
- [ ] Run multiplayer load tests before increasing player capacity

## Multiplayer scaling note
A target of 100–1000+ concurrent players is an architecture and operations goal, not something enabled by this starter code. It requires dedicated servers, backend services, database design, replication budgets, observability, security and staged load testing.
