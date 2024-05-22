C++ Object Oriented Programming and Top Down Design

Project 3: Introduction to Top Down Design by designing a program which first reads the weekly schedules of movie screenings of a town from a csv file.
  Then it manages queries by user, of which there are two type:
  
      1-A command to list all the movies available to watch in the town.
      2-A command which requests the screenings of a specific movie in an HTML. The program has to create a a chart with one axis being the days of the week and the other the hours of the start of screening
        In each cell should be a name of a theather. The priority is given to the one with the cheapest tickets; if there are multiple places with the same lowest price, the one with the lexicographically 
        smallest name is shown.

Project 4: Introduction to Object-Oriented Programming.

      The objective is to design a carwash with a multi-stage pipeline.
      Carwash consists of multiple stages, with multiple workers working in each stage.
      A car has to done at a stage before it can proceed to the next one.
      Each worker has a time coefficient indicating how much time they take to finish.
      Each car has a luxury coefficient indicating the difficulty of cleaning it.
      Overall time it takes for a partticular worker to wash a car is equal to:
            worker_coefficient * car_luxury_coefficient

      The user can work with the following command to add stages with workers, add a car to a queue, and view info.
          1.add_stage "worker_count" "time_coefficient_first_worker"....
          2.add_car "luxury_coefficient"
          3.advance_time "time_steps"
          4.show_stage_info "stage_id"
          5.show_carwash_info
          6.finish 
                this command simulates until all cars are finished washing.

      

