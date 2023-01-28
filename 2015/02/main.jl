function min2(box)
	sort(box)[1:2]
end

function reqpaper(box)
	surface_area = 2 * ([2] * box[3] + box[1] * box[3])
	area = min2(box) |> prod
	
	area + surface_area
end

function reqribbon(box)
	wrap = 2 * sum(min2(box))
	bow = prod(box)

	wrap + bow
end

function solve(countfn)
	split.(readlines("./input.txt"), "x") |> lines -> map(l -> parse.(Int, l), lines) |> boxes -> countfn.(boxes) |> sum |> println 
end

@time solve(reqpaper)
@time solve(reqribbon)

