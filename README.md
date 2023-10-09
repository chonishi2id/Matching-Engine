# Matching Engine Project
 Development started 9/15/2023

 Code base developed by Timothy Chon

 Testing CSVs written by Daniel Jespersen

## Objective
To develop an asset matching engine that matches buy orders of an asset with sell orders of the same asset as fast as possible. The engine is currently modeled off of how the flea market in BattleState Games' *Escape from Tarkov* works.

## Roadmap
### Phase 1
- Comprehensive CSV testing suite
- Working engine demo
### Phase 2
- Matching for varying price ranges
- Matching for multiple different assets
- Optimization fixes
- Timed result tests
### Phase 3
- Multithreading capabilities

## Design Decisions

#### In order to design a matching engine that would be able to match thousands of orders together, the engine must focus on the following criteria:

- Speed: The engine must try to clear order backlogs as fast as possible to not overload storage as well as grant users of the engine faster results.
- Reliability: The engine must not crash under pressure and must be able to run 24/7 (in the case of this simulation, for as long as my desktop is running in a 10 hour session)
- Convenience: The engine must allow users to conveniently follow economic incentives - buyers would prefer to pay as little as possible in purchase, sellers would prefer to sell as high as possible.

#### To meet these criteria, the engine is being designed with the following decisions:

- The entire codebase is in C++ as that is the fastest language in terms of runtime. The code is compiled into machine code which makes runtime faster.
- Multithreading will be implemented to further speed up the number of matches that could be made.
- Multiple priority queues are used to match orders. Currently, orders are ranked based on the order placer's arbitrary "prestige" value but it will later be changed to one that involves the price that the order was placed at.
- Buyers are matched to sellers. The design will cater more towards buyers receiving the matches they desire.


## Other notes
This is a personal side project that I am writing up for fun/to show in interviews. No real financial assets are being traded using this matching engine.