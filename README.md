# Ggg — Unreal Engine 5 MMORPG Starter

A C++ starter project for a planned PC + Android open-world MMORPG.

## Included in this repository

- Unreal Engine project descriptor: `Ggg.uproject` (configured for UE 5.4)
- C++ game module and editor/game target files
- Third-person character with camera boom, camera, walking, turning and jumping
- Default keyboard/mouse input mappings\n- Server-side melee attack trace (left mouse) and replicated enemy health scaffold\n- Replicated inventory item stacks with server-side add/remove functions
- Basic GameMode that spawns the starter character
- Git ignore rules and project roadmap/architecture notes

## Open the project

1. Install Unreal Engine 5.4 and the matching C++ build tools.
2. Download or clone this repository to your computer.
3. Double-click `Ggg.uproject`; allow Unreal to generate project files if prompted.
4. Build the `GggEditor` target in your IDE, then open the project.
5. Create a level in Unreal Editor, add a PlayerStart, and save it under `Content/`.
6. Press Play. The starter pawn uses WASD, mouse look and Space to jump.

## Current status

This is a code scaffold, **not a complete playable MMORPG**. It does not yet include finished 3D character art, animations, an open-world map, combat, inventory, quests, NPC content, login service, database, matchmaking or dedicated multiplayer servers. Those systems must be implemented and tested in later milestones.

A goal of 100–1000+ concurrent players requires authoritative dedicated servers, backend services, persistence, security, monitoring and staged load testing. It is not provided automatically by this starter project.

## Next milestones

See [Docs/ROADMAP.md](Docs/ROADMAP.md) and [Docs/ARCHITECTURE.md](Docs/ARCHITECTURE.md). Use Git LFS for large Unreal binary assets when they are added. Never commit passwords, API keys or production secrets.
