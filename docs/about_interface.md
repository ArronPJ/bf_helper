# About Interface:

## Intro:

- This document use to describe previous experiences.

### Note:

- 3 types of interactions
- (a) sync command call.
- (b) async command call. with callback setup before send request.
- (c) async command request, result would be handle in other components
  - (c-1) partial result only trigger event in callback.
  - (c-2) partial result save in local disk for further usage.
  - (c-3) handle result component can link to multiple handler.
- (d) command request device hold last status (ex: On/Off)
- (e) command queue can implement retry to make sure eventually status the same.

#### D+E:

- 設計概念有點像是上帝模式，為了求得 Viewer 看到的狀態就是所見即所得。
- 另一種概念是 On demand 模式，
  - 每條連線都有自己的 configure , 下指令的對象只影響這條連線獲得的資訊。
  - 訂閱概念
