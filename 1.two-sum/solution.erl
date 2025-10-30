-spec two_sum(Nums :: [integer()], Target :: integer()) -> [integer()].
two_sum(Nums, Target) ->
  f(Nums, 0, Target, #{}).

f([Num | Nums], Idx, Target, Map) ->
  case Map of
    #{Target-Num := Idx2} ->
      [Idx, Idx2];
    _ ->
      f(Nums, Idx+1, Target, Map#{Num => Idx})
  end.
