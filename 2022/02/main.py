from enum import Enum

Move = Enum("Move", "Rock Paper Scissors")

class Scores(Enum):
	Rock = 1
	Paper = 2
	Scissors = 3


def get_move(move: str): 
	match move:
		case "A" | "X": return Move.Rock
		case "B" | "Y": return Move.Paper
		case "C" | "Z": return Move.Scissors

class RoundResult(Enum):
	Win = 6
	Draw = 3
	Loss = 0

class NeededOutcome(Enum):
	Loss = "X"
	Draw = "Y"
	Win = "Z"


def get_strategy_guide(neededOutcome = False) -> list[tuple[Move, Move]]:
	strategy_guide: list[tuple[Move, Move]] = []

	with open("./input.txt", encoding="utf8") as f:
		lines = f.read().split("\n")

		for line in lines:
			enemyPlay, ownPlay = line.split(" ")
			strategy_guide.append([get_move(enemyPlay), get_move(ownPlay) if not neededOutcome else NeededOutcome(ownPlay)])

	return strategy_guide


def round_winner(round: tuple[Move, Move]) -> RoundResult:
	enemyMove, ownMove = round

	if enemyMove == ownMove:
		return RoundResult.Draw

	match ownMove:
		case Move.Rock:
			match enemyMove:
				case Move.Scissors: return RoundResult.Win
				case Move.Paper: return RoundResult.Loss

		case Move.Paper:
			match enemyMove:
				case Move.Rock: return RoundResult.Win
				case Move.Scissors: return RoundResult.Loss

		case Move.Scissors:
			match enemyMove:
				case Move.Paper: return RoundResult.Win
				case Move.Rock: return RoundResult.Loss

		
def total_score(strategy_guide: list[tuple[Move, Move]]) -> int:
	total = 0

	for round in strategy_guide:
		total += Scores[round[1].name].value
		total += round_winner(round).value

	return total


def total_score2(strategy_guide: list[tuple[Move, NeededOutcome]]) -> int:
	total = 0

	for round in strategy_guide:
		own_move = move_for_needed_outcome(round[0], round[1])
		total += Scores[own_move.name].value
		total += round_winner([round[0], own_move]).value

	return total


def move_for_needed_outcome(enemyMove: Move, outcome: NeededOutcome) -> Move:
	if outcome == NeededOutcome.Draw:
		return enemyMove

	match enemyMove:
		case Move.Rock:
			match outcome:
				case NeededOutcome.Win: return Move.Paper
				case NeededOutcome.Loss: return Move.Scissors

		case Move.Paper:
			match outcome:
				case NeededOutcome.Win: return Move.Scissors
				case NeededOutcome.Loss: return Move.Rock

		case Move.Scissors:
			match outcome:
				case NeededOutcome.Win: return Move.Rock
				case NeededOutcome.Loss: return Move.Paper	


if __name__ == "__main__":
	print(f"PART ONE: {total_score(get_strategy_guide())}")
	print(f"PART TWO: {total_score2(get_strategy_guide(True))}")