-spec roman_to_int(S :: unicode:unicode_binary()) -> integer().
roman_to_int(S) ->
  roman_to_int(S, 0, 0, 0).
roman_to_int(S, Idx, Last, V) when Idx >= byte_size(S) ->
  V;
roman_to_int(S, Idx, Last, V) ->
  F = f(binary:at(S, Idx)),
  case Last < F of
    false ->
      roman_to_int(S, Idx + 1, F, V + F);
    true ->
      roman_to_int(S, Idx + 1, F, V + F - 2 * Last)
  end.

f($I) -> 1;
f($V) -> 5;
f($X) -> 10;
f($L) -> 50;
f($C) -> 100;
f($D) -> 500;
f($M) -> 1000.
