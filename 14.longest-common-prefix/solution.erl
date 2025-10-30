-spec longest_common_prefix(Strs :: [unicode:unicode_binary()]) -> unicode:unicode_binary().
longest_common_prefix(Strs) ->
  longest_common_prefix(Strs, 0).
longest_common_prefix(Strs = [S | _], Idx) when Idx >= byte_size(S) ->
  S;
longest_common_prefix(Strs = [S | T], Idx) ->
  C = binary:at(S, Idx),
  case lists:all(fun(X) ->
    Idx < byte_size(X) andalso C =:= binary:at(X, Idx)
  end, T) of
    true ->
      longest_common_prefix(Strs, Idx + 1);
    false ->
      binary_part(S, 0, Idx)
  end.
