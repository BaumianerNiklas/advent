function read_grid()
	grid = zeros(Int, 20, 20)

	for (i, line) ∈ enumerate(readlines("./input.txt"))
		for (j, num) ∈ enumerate(split(line))
			grid[i, j] = parse(Int, num)
		end	
	end

	grid
end

function solve()
	grid = read_grid()
	maxprod = 0


	# Horizontal
	for idx ∈ CartesianIndices(size(grid))
		y = idx[1]
		x = idx[2]
		print("| [$x, $y] ")

		if x ≤ 17
			maxprod = update!(maxprod, horizontal(grid, x, y))
		end

		if y ≤ 17
			maxprod = update!(maxprod, vertical(grid, x, y))
		end

		if x ≤ 17 && y ≤ 17
			maxprod = update!(maxprod, diagonal_l(grid, x, y))
		end

		if x ≥ 4 && y ≤ 17
			maxprod = update!(maxprod, diagonal_r(grid, x, y))
		end
	end

	maxprod |> println
end

function horizontal(grid::Matrix{Int}, x::Int, y::Int)
	grid[y, x:x+3] |> prod
end

function vertical(grid::Matrix{Int}, x::Int, y::Int) 
	grid[y:y+3, x] |> prod
end

function diagonal_l(grid::Matrix{Int}, i::Int, j::Int)
	res = 1

	for k ∈ 0:3
		res *= grid[i + k, j + k]	
	end

	res
end

function diagonal_r(grid::Matrix{Int}, x::Int, y::Int)
	res = 1 

	for k ∈ 0:3
		res *= grid[y + k, x - k]
	end

	res
end

function update!(maxprod::Int, newprod::Int)
	if newprod > maxprod
		println("Updated from $maxprod to $newprod")
		return newprod
	end

	maxprod
end 

solve()