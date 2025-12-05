"""
Statistics Calculator - Python Implementation (Object-Oriented Paradigm)

This program calculates mean, median, and mode of a list of integers
using an object-oriented approach with a StatisticsCalculator class.
"""

from collections import Counter
from typing import List


class StatisticsCalculator:
    """
    A class to calculate basic statistics (mean, median, mode) 
    on a list of integers.
    """
    
    def __init__(self, data: List[int]):
        """
        Initialize the StatisticsCalculator with a list of integers.
        
        Args:
            data: List of integers to calculate statistics on
        """
        self.data = data
    
    def calculate_mean(self) -> float:
        """
        Calculate the mean (average) of the integers.
        
        Returns:
            The mean value as a float. Returns 0.0 if the list is empty.
        """
        if not self.data:
            return 0.0
        
        return sum(self.data) / len(self.data)
    
    def calculate_median(self) -> float:
        """
        Calculate the median (middle value when sorted) of the integers.
        
        Returns:
            The median value as a float. Returns 0.0 if the list is empty.
        """
        if not self.data:
            return 0.0
        
        sorted_data = sorted(self.data)
        length = len(sorted_data)
        
        if length % 2 == 0:
            # Even number of elements: average of two middle values
            mid1 = sorted_data[length // 2 - 1]
            mid2 = sorted_data[length // 2]
            return (mid1 + mid2) / 2.0
        else:
            # Odd number of elements: middle value
            return float(sorted_data[length // 2])
    
    def calculate_mode(self) -> List[int]:
        """
        Calculate the mode (most frequently occurring value(s)) of the integers.
        
        Returns:
            A list of mode values. Returns an empty list if the input is empty.
            If multiple values have the same maximum frequency, all are returned.
        """
        if not self.data:
            return []
        
        # Count frequency of each element
        frequency_counter = Counter(self.data)
        
        # Find the maximum frequency
        max_frequency = max(frequency_counter.values())
        
        # Find all values with the maximum frequency
        modes = [value for value, freq in frequency_counter.items() 
                if freq == max_frequency]
        
        # Sort modes for consistent output
        return sorted(modes)
    
    def print_statistics(self) -> None:
        """
        Calculate and print all statistics (mean, median, mode).
        """
        print("\n=== Statistics Results ===")
        print(f"Data: {self.data}\n")
        
        # Calculate and print mean
        mean = self.calculate_mean()
        print(f"Mean: {mean:.2f}")
        
        # Calculate and print median
        median = self.calculate_median()
        print(f"Median: {median:.2f}")
        
        # Calculate and print mode
        modes = self.calculate_mode()
        print("Mode: ", end="")
        if not modes:
            print("No mode")
        else:
            mode_str = ", ".join(str(m) for m in modes)
            print(mode_str)
        
        print("========================\n")
    
    def get_all_statistics(self) -> dict:
        """
        Calculate and return all statistics as a dictionary.
        
        Returns:
            A dictionary containing 'mean', 'median', and 'mode' keys.
        """
        return {
            'mean': self.calculate_mean(),
            'median': self.calculate_median(),
            'mode': self.calculate_mode()
        }


def main():
    """
    Main function demonstrating the StatisticsCalculator class.
    """
    print("Statistics Calculator - Python Implementation")
    print("==============================================")
    
    # Example 1: Basic example
    calc1 = StatisticsCalculator([1, 2, 3, 4, 5])
    calc1.print_statistics()
    
    # Example 2: With duplicates
    calc2 = StatisticsCalculator([1, 2, 2, 3, 3, 3, 4, 4, 5])
    calc2.print_statistics()
    
    # Example 3: Even number of elements
    calc3 = StatisticsCalculator([10, 20, 30, 40])
    calc3.print_statistics()
    
    # Example 4: Single mode
    calc4 = StatisticsCalculator([5, 5, 5, 2, 2, 1])
    calc4.print_statistics()
    
    # Example 5: Multiple modes
    calc5 = StatisticsCalculator([1, 1, 2, 2, 3, 3])
    calc5.print_statistics()
    
    # Example 6: Using get_all_statistics method
    calc6 = StatisticsCalculator([7, 8, 9, 9, 10])
    stats = calc6.get_all_statistics()
    print("Example using get_all_statistics():")
    print(f"Statistics: {stats}\n")


if __name__ == "__main__":
    main()

