# Serial Protocol Specification

## Message Format
- Commands sent as ASCII strings ending with newline `\n`.
- Format: `COMMAND [ARG1 ARG2 ...]`

## Supported Commands
- MOVE_FORWARD [speed]
- MOVE_BACKWARD [speed]
- TURN_LEFT [speed]
- TURN_RIGHT [speed]
- STOP

## Response
- Acknowledgment messages from Arduino echo the command or report status.

## Example Flow
- PC: MOVE_FORWARD 150
- Arduino: OK MOVE_FORWARD

## Notes
- Speed is an integer 0–255.
- Commands are case-insensitive.
