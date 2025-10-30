%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec merge_two_lists(List1 :: #list_node{} | null, List2 :: #list_node{} | null) -> #list_node{} | null.
merge_two_lists(List1, List2) ->
  merge_two_lists(List1, List2, []).
merge_two_lists(null, null, NewList) ->
  build(NewList, null);
merge_two_lists(null, #list_node{val = Val, next = Next}, NewList) ->
  merge_two_lists(null, Next, [Val | NewList]);
merge_two_lists(#list_node{val = Val, next = Next}, null, NewList) ->
  merge_two_lists(Next, null, [Val | NewList]);
merge_two_lists(List1, List2, NewList) ->
  case List1#list_node.val > List2#list_node.val of
    false ->
      merge_two_lists(List1#list_node.next, List2, [List1#list_node.val | NewList]);
    true ->
      merge_two_lists(List1, List2#list_node.next, [List2#list_node.val | NewList])
  end.

build([], NewList) ->
  NewList;
build([H | T], NewList) ->
  build(T, #list_node{val = H, next = NewList}).
