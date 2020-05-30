### This is a list of supported Scratch blocks in Scrape so far.

Unlike Scratch multi-threading is not supported in Scrape (yet!).

Scrape requires all blocks to have their parameters supplied.

Custom blocks are being worked on at this time.

Scrape stores all integers as a C++ double.

- control_repeat
- control_repeat_until
- control_forever
- control_wait
- control_wait_until
- control_if
- control_if_else
- control_stop
- data_variable
- data_setvariableto
- data_changevariableby
- data_listcontents
- data_addtolist
- data_deleteoflist
- data_deletealloflist
- data_insertatlist
- data_replaceitemoflist
- data_itemoflist
- data_itemnumoflist
    - Unlike Scratch, in Scrape this block is case-sensitive.
- data_lengthoflist
- data_listcontainsitem
- event_whenflagclicked
    - There can only be one event_whenflagclicked block in Scrape at this time.
- looks_say
- looks_think
    - The difference between looks_say and looks_think in Scrape is that looks_say outputs a newline after printing the value supplied.
- operator_add
- operator_subtract
- operator_multiply
- operator_divide
- operator_lt
- operator_equals
    - Unlike Scratch, in Scrape this block is case-sensitive.
- operator_gt
- operator_and
- operator_or
- operator_not
- operator_random
- operator_join
- operator_letter_of
- operator_length
- operator_contains
    - Unlike Scratch, in Scrape this block is case-sensitive.
- operator_mod
- operator_round
- operator_mathop
- sensing_timer
- sensing_resettimer
- sensing_current
- sensing_dayssince2000
- sensing_askandwait
- sensing_answer
- sensing_username
    - In Scrape the sensing_username block will return `<username>`
