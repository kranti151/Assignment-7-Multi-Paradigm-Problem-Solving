(*
 * Statistics Calculator - OCaml Implementation (Functional Paradigm)
 * 
 * This program calculates mean, median, and mode of a list of integers
 * using a functional approach with immutable data structures.
 *)

(* Calculate the mean (average) of integers *)
let calculate_mean lst =
  if lst = [] then 0.0
  else
    let sum = List.fold_left (fun acc x -> acc + x) 0 lst in
    float_of_int sum /. float_of_int (List.length lst)

(* Calculate the median (middle value when sorted) *)
let calculate_median lst =
  if lst = [] then 0.0
  else
    let sorted = List.sort compare lst in
    let len = List.length sorted in
    if len mod 2 = 0 then
      (* Even number of elements: average of two middle values *)
      let mid1 = List.nth sorted (len / 2 - 1) in
      let mid2 = List.nth sorted (len / 2) in
      (float_of_int mid1 +. float_of_int mid2) /. 2.0
    else
      (* Odd number of elements: middle value *)
      float_of_int (List.nth sorted (len / 2))

(* Count frequency of each element in the list *)
let count_frequencies lst =
  List.fold_left
    (fun acc x ->
      if List.mem_assoc x acc then
        List.map (fun (k, v) -> if k = x then (k, v + 1) else (k, v)) acc
      else
        (x, 1) :: acc)
    [] lst

(* Find the maximum frequency *)
let max_frequency freq_list =
  if freq_list = [] then 0
  else
    List.fold_left (fun max_val (_, freq) -> if freq > max_val then freq else max_val) 0 freq_list

(* Calculate the mode (most frequently occurring value(s)) *)
let calculate_mode lst =
  if lst = [] then []
  else
    let freq_list = count_frequencies lst in
    let max_freq = max_frequency freq_list in
    List.fold_left
      (fun acc (value, freq) ->
        if freq = max_freq then value :: acc else acc)
      [] freq_list
    |> List.sort compare

(* Format list as string for printing *)
let list_to_string lst =
  "[" ^ String.concat ", " (List.map string_of_int lst) ^ "]"

(* Print statistics *)
let print_statistics lst =
  print_endline "\n=== Statistics Results ===";
  print_string "Data: ";
  print_endline (list_to_string lst);
  print_newline ();
  
  (* Calculate and print mean *)
  let mean = calculate_mean lst in
  Printf.printf "Mean: %.2f\n" mean;
  
  (* Calculate and print median *)
  let median = calculate_median lst in
  Printf.printf "Median: %.2f\n" median;
  
  (* Calculate and print mode *)
  let modes = calculate_mode lst in
  print_string "Mode: ";
  if modes = [] then
    print_endline "No mode"
  else
    let mode_str = String.concat ", " (List.map string_of_int modes) in
    Printf.printf "%s\n" mode_str;
  
  print_endline "========================\n"

(* Main function *)
let main () =
  print_endline "Statistics Calculator - OCaml Implementation";
  print_endline "=============================================";
  
  (* Example 1: Basic example *)
  let data1 = [1; 2; 3; 4; 5] in
  print_statistics data1;
  
  (* Example 2: With duplicates *)
  let data2 = [1; 2; 2; 3; 3; 3; 4; 4; 5] in
  print_statistics data2;
  
  (* Example 3: Even number of elements *)
  let data3 = [10; 20; 30; 40] in
  print_statistics data3;
  
  (* Example 4: Single mode *)
  let data4 = [5; 5; 5; 2; 2; 1] in
  print_statistics data4;
  
  (* Example 5: Multiple modes *)
  let data5 = [1; 1; 2; 2; 3; 3] in
  print_statistics data5

(* Run the program *)
let () = main ()

