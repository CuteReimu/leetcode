-spec search_insert(Nums :: [integer()], Target :: integer()) -> integer().
search_insert(Nums, Target) ->
  search_insert(Nums, Target, 0).
search_insert([], Target, Idx) ->
  Idx;
search_insert([Target | T], Target, Idx) ->
  Idx;
search_insert([H | T], Target, Idx) when H > Target ->
  Idx;
search_insert([H | T], Target, Idx) ->
  search_insert(T, Target, Idx + 1).
