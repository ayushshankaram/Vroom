use std::io;

fn calculate_multiplier(remaining_non_mine_cells: i32, remaining_cells: i32) -> f64 {
    let success_probability = remaining_non_mine_cells as f64 / remaining_cells as f64;
    let multiplier = 1.0 / success_probability;
    multiplier
}

fn get_combined_multiplier(grid_size: i32, total_mines: i32, taps: i32) -> f64 {
    let total_cells = grid_size * grid_size;
    let non_mine_cells = total_cells - total_mines;
    let mut combined_multiplier = 1.0;

    let mut remaining_non_mine_cells = non_mine_cells;
    let mut remaining_cells = total_cells;

    for _ in 0..taps {
        let current_multiplier = calculate_multiplier(remaining_non_mine_cells, remaining_cells);
        combined_multiplier *= current_multiplier;

        remaining_non_mine_cells -= 1;
        remaining_cells -= 1;
    }

    combined_multiplier
}

fn main() {
    let grid_size: i32 = 5;
    let mut total_mines = String::new();
    let mut taps = String::new();

    println!("Enter the number of mines: ");
    io::stdin().read_line(&mut total_mines).expect("Failed to read input.");
    let total_mines: i32 = total_mines.trim().parse().expect("Invalid input.");

    println!("Enter the number of taps: ");
    io::stdin().read_line(&mut taps).expect("Failed to read input.");
    let taps: i32 = taps.trim().parse().expect("Invalid input.");

    if total_mines >= grid_size * grid_size {
        println!("Invalid number of mines. The number of mines must be less than the total number of cells.");
        return;
    }

    if taps > grid_size * grid_size - total_mines {
        println!("Invalid number of taps. The number of taps must be less than or equal to the number of non-mine cells.");
        return;
    }

    let multiplier = get_combined_multiplier(grid_size, total_mines, taps);
    println!("Combined multiplier after {} taps with {} mines in a {}x{} grid: {}", taps, total_mines, grid_size, grid_size, multiplier);
}
