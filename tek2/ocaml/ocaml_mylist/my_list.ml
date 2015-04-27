(* 
* @Author: gicque_p
* @Date:   2015-02-16 21:33:42
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-03-05 15:51:09
*)

type 'a my_list = 
	| Item of ('a * 'a my_list)
	| Empty
;;

(* ---------- Length function ---------- *)

let length my_list =
	let rec len number = function
		| Empty -> number
		| Item(_, tail) -> len (number + 1) tail 
	in len 0 my_list
;;

(* ---------- Hd function ---------- *)

let hd my_list = match my_list with
	| Empty -> raise (Failure "hd")
	| Item (head, _) -> head
;;

(* ---------- Tl function ---------- *)

let tl my_list = match my_list with
	| Empty -> raise (Failure "tl")
	| Item (_, tail) -> tail
;;

(* ---------- Nth function ---------- *)

let rec nth my_list number =
	match number with
		| n when n < 0 -> raise (Invalid_argument "List.nth")
		| n when n > length my_list -> raise (Failure "nth")
		| n when n == 0 -> (hd my_list)
		| _-> match my_list with
			| Empty -> raise (Failure "tl")
			| Item (head, tail) -> nth tail (number - 1)
;;

(* ---------- Rev function ---------- *)

let rev my_list =
	let rec aux reverseList = function
		| Empty -> reverseList
		| Item (head, tail) -> aux (Item (head, reverseList)) tail
	in aux Empty my_list
;;

(* ---------- Append function ---------- *)

let append my_list appendList =
	let rec app aux = function
		| Empty -> aux
		| Item (head, tail) -> app (Item (head, aux)) tail
	in app appendList (rev my_list)
;;

(* ---------- Rev_Append function ---------- *)

let rev_append my_list appendList =
	append (rev my_list) appendList
;;

(* ---------- Flatten function ---------- *)

let flatten my_list =
	let rec flat aux = function
		| Empty -> rev aux
		| Item(head, tail) -> flat (rev_append head aux) tail
	in flat Empty my_list
;;

(* ---------- Iter function ---------- *)

let rec iter funct = function
	| Empty -> ()
	| Item (head, tail) ->
		begin
			funct head;
			iter funct tail;
		end
;;

(* ---------- Map function ---------- *)

let rec map funct = function
	| Empty -> Empty
	| Item (head, tail) -> Item(funct head, map funct tail)
;;

(* ---------- Fold_Left function ---------- *)

let rec fold_left funct a = function
	| Empty -> a
	| Item (head, tail) -> fold_left funct (funct a head) tail
;;

(* ---------- For_All function ---------- *)

let rec for_all funct = function
	| Empty -> true
	| Item (head, tail) -> funct head && for_all funct tail
;;

(* ---------- Exists function ---------- *)

let rec exists funct = function
	| Empty -> false
	| Item (head, tail) -> funct head || exists funct tail
;;

(* ---------- Mem function ---------- *)

let mem value my_list =
	let rec memory boolean value = function 
		| Empty -> boolean
		| Item (head, tail) -> head = value || memory (head = value) value tail
	in memory false value my_list
;;

(* ---------- Memq function ---------- *)

let memq value my_list =
	let rec memory boolean value = function 
		| Empty -> boolean
		| Item (head, tail) -> head == value || memory (head == value) value tail
	in memory false value my_list
;;

(* ---------- Filter function ---------- *)

let filter value =
	let rec find aux = function 
		| Empty -> rev aux
		| Item (head, tail) -> 
			if value head
				then find (Item (head, aux)) tail
			else find aux tail
	in find Empty
;;

(* ---------- Assoc function ---------- *)

let rec assoc value = function
	| Empty -> raise Not_found
	| Item ((head, tail), secondTail) ->
		if head = value
		then tail
		else assoc value secondTail
;;

(* ---------- Mem_Assoc function ---------- *)

let rec mem_assoc value = function
	| Empty -> false
	| Item ((head, tail), secondTail) ->
		if head = value
		then true
		else mem_assoc value secondTail
;;

(* ---------- Remove_Assoc function ---------- *)

let rec remove_assoc value = function
	| Empty -> raise Not_found
	| Item ((head, tail), secondTail) ->
		if head = value
		then secondTail
		else remove_assoc value secondTail
;;

(* ---------- Split function ---------- *)

let rec split = function
	| Empty-> (Empty, Empty)
	| Item ((head, tail), secondTail) -> let (a, b) = split secondTail in (Item (head, a), Item (tail, b))
;;
