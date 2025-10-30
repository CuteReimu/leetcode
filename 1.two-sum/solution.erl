-spec two_sum(Nums :: [integer()], Target :: integer()) -> [integer()].
two_sum(Nums, Target) ->
  A = lists:zip(Nums, lists:seq(0, length(Nums) - 1)),
  lists:foldl(fun({Num, Idx}, AccIn) ->
    case AccIn of
      undefined ->
        case lists:search(fun({Num2, Idx2}) ->
          Idx /= Idx2 andalso Target == Num2 + Num
        end, A) of
          {value, {Num1, Idx1}} ->
            [Idx, Idx1];
          false ->
            undefined
        end;
      Other ->
        Other
    end
  end, undefined, A).
