-spec is_valid(S :: unicode:unicode_binary()) -> boolean().
is_valid(S) ->
  is_valid(S, 0, []).
is_valid(S, Idx, L) when Idx >= byte_size(S) ->
  length(L) == 0;
is_valid(S, Idx, L) ->
  case binary:at(S, Idx) of
    C when C =:= ${ orelse C =:= $[ orelse C=:= $( ->
      is_valid(S, Idx+1, [C | L]);
    C ->
      case L of
        [H | T] when H =:= C - 1 orelse H =:= C - 2 ->
          is_valid(S, Idx+1, T);
        _ ->
          false
      end
  end.
