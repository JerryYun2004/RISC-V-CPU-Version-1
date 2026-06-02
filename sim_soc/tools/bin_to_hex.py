#!/usr/bin/env python3
import argparse
from pathlib import Path

parser = argparse.ArgumentParser(description="Convert little-endian binary to one 32-bit word per line hex.")
parser.add_argument("input_bin")
parser.add_argument("output_hex")
args = parser.parse_args()

data = Path(args.input_bin).read_bytes()
if len(data) % 4:
    data += bytes(4 - (len(data) % 4))

lines = []
for i in range(0, len(data), 4):
    word = int.from_bytes(data[i:i+4], byteorder="little")
    lines.append(f"{word:08x}\n")

Path(args.output_hex).parent.mkdir(parents=True, exist_ok=True)
Path(args.output_hex).write_text("".join(lines))
