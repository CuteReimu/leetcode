-spec sum_of_three(Num :: integer()) -> [integer()].
sum_of_three(Num) ->
  case Num rem 3 == 0 of
    false ->
      [];
    true ->
      [Num div 3 - 1, Num div 3, Num div 3 + 1]
  end.
