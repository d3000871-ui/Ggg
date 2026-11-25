# Initial architecture

- **Game client (UE5):** rendering, input, local presentation and prediction.
- **Dedicated game server:** authoritative movement/combat validation and world state.
- **Backend API:** accounts, character profiles, inventory persistence and matchmaking.
- **Database:** durable player and world data.

Never trust client-submitted currency, inventory, damage or progression values. Validate gameplay-changing requests on the server. Do not store passwords or production secrets in this repository.

This document is a proposed starting architecture; no backend or dedicated server is implemented yet.
