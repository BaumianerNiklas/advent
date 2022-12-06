signal = ""

with open("./input.txt") as f:
	signal = f.read()


def solve(markerlen):
	i = markerlen
	while i < len(signal):
		letters = set(signal[i - markerlen:i])
		if len(letters) == markerlen:
			break

		i += 1

	return i


print(solve(4))
print(solve(14))