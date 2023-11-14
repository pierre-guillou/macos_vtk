#include <iostream>

#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDataSet.h>
#include <vtkDelaunay2D.h>
#include <vtkDelimitedTextReader.h>
#include <vtkDelimitedTextWriter.h>
#include <vtkDoubleArray.h>
#include <vtkHexahedron.h>
#include <vtkInformation.h>
#include <vtkInformationDoubleKey.h>
#include <vtkMultiBlockDataSet.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyLine.h>
#include <vtkPolygon.h>
#include <vtkQuad.h>
#include <vtkRectilinearGrid.h>
#include <vtkStringArray.h>
#include <vtkTable.h>
#include <vtkTableReader.h>
#include <vtkTableWriter.h>
#include <vtkTriangle.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVariantArray.h>
#include <vtkVertex.h>
#include <vtkXMLDataReader.h>
#include <vtkXMLGenericDataObjectReader.h>
#include <vtkXMLMultiBlockDataReader.h>
#include <vtkXMLMultiBlockDataWriter.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkXMLRectilinearGridReader.h>
#include <vtkXMLRectilinearGridWriter.h>
#include <vtkXMLTableReader.h>
#include <vtkXMLTableWriter.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkXMLUnstructuredGridWriter.h>

std::string get_vtk_filename_suffix(const int mesh_type) {
  switch (mesh_type) {
  case VTK_POLY_DATA:
    return "vtp";
  case VTK_RECTILINEAR_GRID:
    return "vtr";
  case VTK_UNSTRUCTURED_GRID:
    return "vtu";
  default:
    return "vtk";
  }
}

int main() {
  vtkSmartPointer<vtkMultiBlockDataSet> blocks;
  vtkSmartPointer<vtkXMLWriter> writer0;
  vtkNew<vtkXMLMultiBlockDataWriter> writer1;
  vtkSmartPointer<vtkDataSet> ds;

  vtkNew<vtkTable> table{};
  vtkNew<vtkDoubleArray> data{};
  data->SetNumberOfComponents(1);
  std::string field("Value");
  data->SetName(field.c_str());
  data->SetComponentName(0, "");

  std::cout << "hello world" << std::endl;
  std::cout << data->GetName() << std::endl;
  std::srand(std::time(nullptr));
  std::cout << get_vtk_filename_suffix(std::rand() % 5) << std::endl;
  return 0;
}
