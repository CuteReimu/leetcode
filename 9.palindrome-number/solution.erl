-spec is_palindrome(X :: integer()) -> boolean().
is_palindrome(X) when X < 0 ->
  false;
is_palindrome(X) ->
  reverse(X, []) =:= X.

build(X, _, []) ->
  X;
build(X, I, [N | L]) ->
  build(X + N * I, I * 10, L).

reverse(0, L) ->
  build(0, 1, L);
reverse(X, L) ->
  reverse(X div 10, [X rem 10 | L]).
